let steps = [];
let currentStep = 0;
let autoInterval = null;
let insertedNodes = [];

async function loadSteps() {
    try {
        const response = await fetch('steps.json');
        steps = await response.json();
        currentStep = 0;
        insertedNodes = [];
        document.getElementById('treeContainer').innerHTML = '';
        document.getElementById('logBox').innerHTML = '<div class="log-entry" style="color:#3498db;">Loaded ' + steps.length + ' steps successfully!</div>';
        document.getElementById('nextBtn').disabled = false;
        document.getElementById('autoBtn').disabled = false;
    } catch (error) {
        alert('Could not load steps.json. Make sure the file exists in your project directory.');
    }
}

function nextStep() {
    if (currentStep < steps.length) {
        const step = steps[currentStep];
        const logBox = document.getElementById('logBox');
        
        const entry = document.createElement('div');
        entry.className = 'log-entry';
        const actionText = step.action || step.log || "INSERT";
        const valText = step.value !== undefined ? step.value : "";
        entry.innerHTML = `<span class="step-num">[Step ${currentStep + 1}]</span> <span class="action">${actionText}</span> : <span class="value">${valText}</span>`;
        logBox.appendChild(entry);
        logBox.scrollTop = logBox.scrollHeight;

   
        if (step.value !== undefined && !isNaN(parseInt(step.value))) {
            const val = parseInt(step.value);
            if (!insertedNodes.includes(val)) {
                insertedNodes.push(val);
                renderTreeNode(val);
            }
        }

        currentStep++;
    } else {
        if (autoInterval) clearInterval(autoInterval);
        alert('Visualization Completed!');
    }
}

function renderTreeNode(val) {
    const container = document.getElementById('treeContainer');
    

    document.querySelectorAll('.tree-node').forEach(node => node.classList.remove('new-node'));

    const node = document.createElement('div');
    node.className = 'tree-node new-node';
    node.innerText = val;

    // 
    if (insertedNodes.length === 1) {
        node.style.top = '40px';
        node.style.left = 'calc(50% - 25px)';
    } else if (insertedNodes.length === 2) {
        node.style.top = '120px';
        node.style.left = 'calc(35% - 25px)';
    } else {
        node.style.top = `${40 + (insertedNodes.length - 1) * 60}px`;
        node.style.left = `calc(${50 + (insertedNodes.length % 2 === 0 ? -15 : 15)}% - 25px)`;
    }

    container.appendChild(node);
}

function toggleAutoPlay() {
    const btn = document.getElementById('autoBtn');
    if (autoInterval) {
        clearInterval(autoInterval);
        autoInterval = null;
        btn.innerText = 'Auto Play';
    } else {
        btn.innerText = 'Pause';
        autoInterval = setInterval(nextStep, 500);
    }
}